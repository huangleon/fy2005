// ; annie 07.2003
// dancing_faery@hotmail.com
// 

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
�������幬���²�Ϊ����֪��һ�����ң���������Ϊ�ڵص׵�Ե�ʣ�
�����д���һ���������Ƶĳ�ʪ�����ҵĵ��ϻ��Ż��ཻ�ϵ�һ��һС��
�����ǣ���Ե������������øɺԵ�ѪҺ���Ÿ��ַ��ģ����ıڲ���ɫ��
�ҵ�ӳ�����Ե÷�����졣
LONG
        );
	set("no_fly",1);
	set("objects", ([
		__DIR__"npc/xin" : 1,
	]));   
	setup();
}

void pushout()
{
	object *inv;
	int i;
	inv = all_inventory(this_object());
	for (i=0;i<sizeof(inv); i++)
		if (userp(inv[i]))
			call_out("do_greeting",30,inv[i],this_object());
}

void do_greeting(object me,object room)
{
	if (!me || environment(me) != room)
		return;

	message_vision(CYN"\nһ�ŷ����׹�ķ�ֽ��Ȼ������$N���ϣ�$N����Ӱ���ڿ�����ģ������\n\n"NOR,me);
	me->move(load_object("/d/taoguan/taoguan"));
	message_vision(CYN"\n����ǰ�Ŀ�����Ȼ��ʼ���󲨶���һ��ģ�������������Ĵ���������ֳ���������\n\n"NOR,me);
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

