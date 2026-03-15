# CPP-42

All 42 CPP modules in a single repository, pushed individually to Vogsphere.

## Setup

### Adding a Vogsphere remote

```bash
git remote add M00 git@vogsphere.42paris.fr:vogsphere/intra-uuid-<your-uuid>
```

Repeat for each module (`M01`, `M02`, etc.).

## Pushing a module to Vogsphere

`git subtree push` often fails with `"no new revisions found"` when commits touch files outside the module folder. Use this method instead:

### 1. Create an orphan branch with the module content

```bash
git checkout --orphan temp-branch
git rm -rf --cached .
git read-tree --prefix="" HEAD:<module_folder>
git commit -m "<module_folder>"
```

For example, to push `CPP_02`:

```bash
git checkout --orphan temp-branch
git rm -rf --cached .
git read-tree --prefix="" HEAD:CPP_02
git commit -m "CPP_02"
```

### 2. Push to Vogsphere

```bash
git push M02 temp-branch:master
```

### 3. Clean up

```bash
git checkout -f master
git branch -D temp-branch
```

## Avoiding the issue altogether

If you want `git subtree push --prefix CPP_XX MXX master` to work directly, make sure each commit only touches files **inside** the module folder. Don't mix changes to root-level files (like `.gitignore`) in the same commit.
