Пример плагина для SurvivalShop, добавляющего новый тип кастомного товара "permissions"

Read in English: https://github.com/admin4eg/survivalshop-api/blob/master/README.en.md

Пример custom.json:

// при покупке товара пользователь будет добавлен в группу "Premium"

`{`
`	"type": "permissions",`
`	"do": "add",`
`	"group": "Premium"`
`}`

// при покупке товара пользователь будет удален из группы "RestrictBuilding"

`{`
`	"type": "permissions",`
`	"do": "remove",`
`	"group": "RestrictBuilding"`
`}`

Больше информации:

http://www.survivalshop.wiki