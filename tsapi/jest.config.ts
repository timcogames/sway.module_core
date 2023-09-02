import { pathsToModuleNameMapper } from "ts-jest"
import type { JestConfigWithTsJest } from "ts-jest";

const tsConfig = require("./tsconfig.json");
const jestConfig: JestConfigWithTsJest = {
  roots: ["<rootDir>"],
  testEnvironment: "node",
  preset: "ts-jest",
  modulePaths: [tsConfig.compilerOptions.baseUrl],
  moduleFileExtensions: ["js", "ts"],
  moduleNameMapper: pathsToModuleNameMapper(tsConfig.compilerOptions.paths, { prefix: "<rootDir>/" }),
  transform: {
    "^.+\\.ts$": ["ts-jest", {}]
  },
  testMatch: [
    "<rootDir>/tests/jest/*.spec.+(js|ts)"
  ]
};

export default jestConfig;
