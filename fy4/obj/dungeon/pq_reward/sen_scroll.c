#include <ansi.h>
inherit __DIR__"scroll.c";

void create()
{
	set_name("��"MAG"��İ��ƪ������ľ�"NOR"��"NOR, ({ "scroll" }));
	set_weight(1000);
	if( clonep() )
			set_default_object(__FILE__);
	else {
            set("long",YEL"һ������˿������Ķ�(Read)��ѧϰ���������ص�������\n"NOR);
			set("value", 1000);
			set("unit", "��");
			set("material", "paper");
			set("teaching", "sen");
	}
}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
