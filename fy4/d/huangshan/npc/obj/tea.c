inherit ITEM;

void create()
{
        set_name("�����", ({ "tea", "yunwu cha", "�����" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Щ");
                set("long", "����ɫ�Ĳ�Ҷ�ϴ�������ɫ����ë�������������˱ǡ�\n");
                set("value", 200);
                set("����", 1);
        }
	::init_item();
}


