// ; annie 07.2003
// dancing_faery@hotmail.com
// 
inherit ITEM;

void create()
{
        set_name("СֽƬ", ({ "paper"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "\n��������\n\n����ɽׯ\n������\n");
				set("no_split",1);
                set("value", 1);
        }
}



/*
�� ������ �� ��
�� �ž�ɽ �� ��
�� ��ɽׯ �� ��
�� ���õ� �� ��
*/