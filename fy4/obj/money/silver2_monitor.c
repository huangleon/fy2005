// silver.c

inherit MONEY;

void create()
{
	set_name("����", ({"silver", "ingot", "silver_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "silver");
		set("long", "�׻��������ӣ��˼��˰������ӡ�\n");
		set("unit", "Щ");
		set("base_value", 100);
		set("base_unit", "��");
		set("base_weight", 37);
	}
	set_amount(1);
	log_file("silver",sprintf("%O attach silver at %s",previous_object(),ctime(time())));
}

