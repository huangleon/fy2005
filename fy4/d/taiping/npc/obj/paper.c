
inherit ITEM;

void create()
{
        set_name("��ͼ", ({"paper", "map",  "ֽ"}) );
	set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ŵ�ͼ����򵥵�����һ��ׯԺ��ī���ĵ�ͼ������ȴ���������ɫ���棬
һ����תǽ�Աߣ�һ��ȴ����һ��С¥֮�ϣ��Ա߻��������֡���Ѫū��
��ͼ�½�д�ţ������������ߣ��ɿ���ǽ���š�
\n");
                set("value", 1);
        }
}

