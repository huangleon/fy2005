
inherit ITEM;

void create()
{
    set_name("���", ({ "qiu yin", "qiuyin"}) );
	set_weight(1);
    if( clonep() )
    	set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "����ɫ���Ӱ��ϸ����򾡣 \n");
        set("value", 1);
		set("fish_bait", 1);
    }
}

