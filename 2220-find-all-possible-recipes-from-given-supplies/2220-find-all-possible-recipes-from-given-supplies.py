class Solution:
    def dfs(self, theGraph, currNode, visited, recStack, toporder):
        visited[currNode] = True
        for neighbor in theGraph[currNode]:
            if recStack[neighbor] == True:
                return True
            if not visited[neighbor]:
                visited[neighbor] = True
                recStack[neighbor] = True
                containsCycle = self.dfs(theGraph, neighbor, visited, recStack, toporder)
                if containsCycle:
                    return True
                recStack[neighbor] = False

        toporder.append(currNode)
        return False

    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        supplies = set(supplies)
        recipes_set = set(recipes)
        theGraph = {}
        visited = {}
        recStack = {}
        for i in range(len(recipes)):
            allingredients = []
            isValid = True
            for j in range(len(ingredients[i])):
                if ingredients[i][j] not in supplies and ingredients[i][j] not in recipes_set:
                    isValid = False
                    break
                elif ingredients[i][j] not in supplies and ingredients[i][j] in recipes_set:
                    allingredients.append(ingredients[i][j])
            if isValid:
                theGraph[recipes[i]] = allingredients
            else:
                theGraph[recipes[i]] = [recipes[i]]
            visited[recipes[i]] = False
            recStack[recipes[i]] = False
        possiblerecipes = []

        for recipe in theGraph:
            toporder = []
            for i in visited:
                visited[i] = False
            recStack[recipe] = True
            containsCycle = self.dfs(theGraph, recipe, visited, recStack, toporder)
            recStack[recipe] = False
            if not containsCycle:
                possiblerecipes.append(recipe)
        return possiblerecipes
        

        