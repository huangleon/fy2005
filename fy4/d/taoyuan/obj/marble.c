
inherit ITEM;

void create()
{
	set_name("ˮ����", ({ "crystal ball" , "ˮ����"}) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����Ө��͸��ˮ���򣬱��������һ�����ĵ�����������\n");
		set("value", 0);

			set("weapon_material",1);
			set("material_level",54);
			set("desc_ext","��������(54)");

	}
    ::init_item();
}

void init()
{
        add_action("do_use", "use");
}

int do_use(string arg)
{
        if( arg != "crystal ball" ) return 0;

        tell_object(this_player(),"���ͳ�һ��" + this_object()->name() + "��\n");

        return 1;
}


