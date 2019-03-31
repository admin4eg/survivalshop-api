A sample plugin which adds new "permissions" goods to SurvivalShop using ShopAPI

Пример плагина для SurvivalShop, добавляющего новый тип кастомного товара "permissions"

Пример custom.json:

// при покупке товара пользователь будет добавлен в группу "Premium"
{
	"type": "permissions",
	"do": "add",
	"group": "Premium"
}

// при покупке товара пользователь будет удален из группы "RestrictBuilding"
{
	"type": "permissions",
	"do": "remove",
	"group": "RestrictBuilding"
}

Больше информации:

http://www.survivalshop.org
http://www.survivalshop.wiki