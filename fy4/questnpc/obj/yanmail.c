//XXDER
inherit ITEM;
void create()
{
        set_name("��", ({ "letter", "��"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
				set("long",
"һ���û����õ��ź�������д�š���ɽׯ���˾�������\n"
);
				set("for_xie_test",1);
        }
       ::init_item();
}
 
