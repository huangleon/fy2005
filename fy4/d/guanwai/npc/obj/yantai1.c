inherit ITEM;

void create()
{
        set_name("��̨", ({ "yan tai", "�Ϻ���̨", }) );
        set_weight(1300);
        set_max_encumbrance(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�Ϻ�ɫ����̨����Ө�࣬��̨�ı��ϰ���ʯͷ������ɫ������һ�ú�÷����\n");
                set("value", 1000);
                set("color", "�Ϻ�");
        }
	::init_item();
}


