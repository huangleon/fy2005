
inherit ITEM;

void create()
{
	set_name("��������ͼ", ({"��������ͼ", "arcane graphics" ,"drawing" }) );
	set_weight(500);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���ڵ��ϵ�����ͼ�Σ���������������֪�Ǻκ��塣\n");
		set("value", 1);
        set("skill", ([
                "name":        "starrain", 
                "exp_required": 0,                  
                "sen_cost":     35,         
                "difficulty":   35,                 
				"literate" :    "starrain",
				"liter_level":  95,
                "max_skill":    95,
        ]) );
	}
    ::init_item();
}

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
