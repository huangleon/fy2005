
inherit ITEM;

void create()
{
        set_name("���Ƶ�ֽ", ({"paper", "bao map",  "ֽ"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ���Ѿ������˵�ֽ��������ּ���ȱ��ȫ������Լ�ɱ��ĸ��֡�
	��ˮ                   
                       ����
\n");
                set("value", 1);
        }
}

