//tenthousand-cash.c

inherit MONEY;

void create()
{
	set_name("һ������Ʊ", ({"tenthousand-cash", "tenthousand-cash_money", "ttcash"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "thousand-cash");
		set("long", "һ�����ֵһ�������ӵ���Ʊ��\n");
		set("unit", "��");
		set("base_value", 1000000);
		set("base_unit", "��");
		set("base_weight", 3);
	}
	set_amount(1);
}

