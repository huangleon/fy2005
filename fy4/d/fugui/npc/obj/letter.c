inherit ITEM;

void create()
{
        set_name("�Ƽ���", ({ "letter", "��"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("unit", "��");
                set("long", "һ���Ƽ��ţ��ϱ�д�ţ�
���˧������Ӣ�����䣬���������������������ƴ�֮��
        
����                   
        ����
\n");
	}
        set("value", 0);
	::init_item();
}
