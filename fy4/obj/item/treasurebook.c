#include <ansi.h>
inherit ITEM;

void create()
{
    	set_name("����������ҳ", ({ "book"}) );
    	set_weight(5);
    	if( clonep() )
        	set_default_object(__FILE__);
    	else {
        	set("unit", "��");
        	set("no_split", 1);
        	set("long","������������������������������������书�ķ�������
ǰ�����齻����ʫ����ϣ���ֵ���������Ѱ������Ϊ�Լ�
��һ�����ʸߡ����������²����ˡ�����Ѱ���Ϲٽ���
��֮�գ���������Х�Ʊ�ɱ���Ӵ�ʧ���������������ƺ�
�����е�һ����ҳ��\n");
        	set("value", 0);
        	set("desc_ext","�޼�֮�����ܻ���ʲô�أ�");
        	set("pfm_r1",1);
    	}
    	::init_item();
}
