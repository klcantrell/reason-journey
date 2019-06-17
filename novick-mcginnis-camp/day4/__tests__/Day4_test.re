open Jest;

describe("Simple test", () => {
  open Expect;

  test("Add example", () => {
    expect(1 + 2) |> toBe(3);
  })
});


describe("Response", () => {
  open Expect;
  open Day4HomeworkRecap;

  test("Loading state should respond with 'Loading'", () => {
    expect(response(Loading)) |> toBe("Loading");
  });

  test("General success state", () => {
    expect(response(Success({ name: "John", age: 10 }))) |> toBe("John");
  });

  test("Vladimir Novick success state", () => {
    expect(response(Success({ name: "Vladimir Novick", age: 30 }))) |> toBe("Howdy Vladimir");
  })
});