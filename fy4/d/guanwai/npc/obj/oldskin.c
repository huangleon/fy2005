inherit ITEM;

void create()
{
        set_name("��Ƥʫ��", ({"sheep skin", "sheepskin",  "skin"}) );
	set_weight(250);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("unit", "��");
                set("long", "һ��ʮ���ƾɵ���Ƥʫ���ּ�ģ��������ϡ���Ա��ϣ�
     ������ �� �� ��
     ������ �� �� ��
     ������ �� �� ��
     ����   ̸    ��
\n");
                set("value", 0);
        }
	::init_item();
}
