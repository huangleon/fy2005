inherit ITEM;

void create()
{
        set_name("�ʯ", ({ "she shi", "�ʯ", "stone", }) );
        set_weight(1500);
        set_max_encumbrance(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��˫�ƴ�Сɫ����̣�����Ө�࣬ߵ֮����������Ѥ�õ�ʯͷ��
������̨���Ϻ�ʯ�ϡ�\n");
                set("value", 500);
                set("color", "��");
                set("��̨��", 1);
        }
	::init_item();
}


