// coin.c

inherit MONEY;

void create()
{
	set_name("ͭǮ", ({"special coin", "coin" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "coin");
		set("long","������ͨ�е�λ��С�Ļ��ң�ԼҪһ����Ǯ��ֵ��һ�����ӡ�
��ֵ������ͭǮ����һ��ǳǳ���Ѻۡ�\n");
		set("unit", "ö");
		set("base_value", 1);
		set("base_unit", "��");
		set("base_weight", 1);
		set("marks","special_coin");
	}
	set_amount(1);
}

