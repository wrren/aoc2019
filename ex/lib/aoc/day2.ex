defmodule AOC.Day2 do
  require Logger

  @doc """
  Read the program at the given path
  """
  def read(path) do
    path
    |> File.read!()
    |> String.split(",")
    |> Enum.reduce([], fn(s, out) ->
      case Integer.parse(s) do
        {i, _}  -> [i | out]
        _       -> out
      end
    end)
    |> Enum.reverse()
  end

  @doc """
  Run the given program and return the result
  """
  def run(program),
    do: run(program, 0)
  def run([result | _] = program, offset) when is_list(program) do
    program
    |> Enum.slice(offset, 4)
    |> case do
      [1, i1, i2, o] ->
        run(List.replace_at(program, o, Enum.at(program, i1) + Enum.at(program, i2)), offset + 4)
      [2, i1, i2, o] ->
        run(List.replace_at(program, o, Enum.at(program, i1) * Enum.at(program, i2)), offset + 4)
      [99 | _] ->
        result
    end
  end

  @doc """
  Set the initial program state by inputting the given noun and verb pair into the program
  """
  def set_program_state(program, noun, verb) do
    program
    |> List.replace_at(1, noun)
    |> List.replace_at(2, verb)
  end

  @doc """
  Find an input noun and verb pair that produce the given result
  """
  def find_inputs_for_result(program, result),
    do: find_inputs_for_result(program, result, 0, 0, run(set_program_state(program, 0, 0)))
  def find_inputs_for_result(_program, result, noun, verb, result),
    do: {noun, verb, (100 * noun) + verb}
  def find_inputs_for_result(_program, _result, 100, _, _),
    do: :error
  def find_inputs_for_result(program, result, noun, 100, _last),
    do: find_inputs_for_result(program, result, noun + 1, 0, run(set_program_state(program, noun + 1, 0)))
  def find_inputs_for_result(program, result, noun, verb, _last),
    do: find_inputs_for_result(program, result, noun, verb + 1, run(set_program_state(program, noun, verb + 1)))
end
