
inherit ITEM;

void create()
{
	set_name("������������", ({"������������", "������" ,"statue" }) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ��ׯ�����µ�ǧ�ֹ�������������ƽ�������Ĺ������в�ͬ��\n");
		set("value", 1);
        set("skill", ([
                "name":        "chanting", 
                "exp_required": 0,                  
                "sen_cost":     35,         
                "difficulty":   35,                 
				"literate" :    "chanting",
				"liter_level":  95,
                "max_skill":    95,
        ]) );
	}
    ::init_item();
}

int is_container() { return 1; }

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
