inherit ITEM;

void create()
{
        set_name("����", ({ "mache", "cart" }) );
        set_weight(500);
        set_max_encumbrance(80000);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "
һ������һ�����ӵ������Һ���̣��ƺ���ϲ���õġ�������������
�˽ٵ��Ĵ�ͽ���������һ��������\n");
                set("value", 1);
        }
}

int is_container() { return 1; }

