inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("��ɽʯ��", ({ "shi er", "��ɽʯ��" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "���Ҷ״���������ɫ��������������״ͻ���\n");
                set("unit", "Щ");
                set("value", 400);
                set("food_remaining", 5);
                set("food_supply", 10);
        }
	::init_item();
}

