#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("ʮ�������", ({ "shimian music" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ҳ");
                set("long","
�������ᰮ���ֵ������ټ����������˽����������ַ���
��ϸͼ���˼�ֻ�����ɣ������⾳��ֻҪ�����ģ���ͨ��
������Ҳ����������Ŀ��ֻ���������ַ�������Ӳ����
�޷��ڻ��ͨ��ѧ����һ����Ŀ�������ǰ���������⡣
��������150�ٵ���");
                set("value", 1000000);
				set("material", "paper");
				set("desc_ext","��Ħ��activate��");
        }
        ::init_item();
}


void init()
{
	   	add_action("do_activate","activate");
}
    
// 	��1"HIY"ʮ������� "HIW"2"HIY"����ˮ���� "HIW"3"HIY"�̺������� "HIW"4"HIY"���������� "
    
int do_activate(string arg)
{
    	object me = this_player();

		if (!arg || arg != "shimian music"){
			tell_object(me,"��ʽ��activate shimian music\n");
			return 1;
		}
		
		if (me->query_skill("music",1)<150) {
			tell_object(me,"����ַ�ʵ��̫����׶����а�����150�ٵ���\n");
			return 1;
		}
					
		tell_object(me, "���ധĦ�����ڱ�����ʮ�����������ϧ���Թ��ȣ�ԭ��ѧ�Ķ����ˡ�\n")	;	
		
        me->set("annie/music_choose",1);
        destruct(this_object());
    	return 1;
}

