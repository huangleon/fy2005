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
�������幬���²�Ϊ����֪��һ�����ң���������Ϊ�ڵص׵�Ե�ʣ�����
�д���һ���������Ƶĳ�ʪ���������������ϰ����˸��ַ��Ƶ����伮��
һ�����°׷������糤�룬�����������ɷ��������վ�����ǰһյ��������
�����������еĹ�����
LONG
        );
	set("no_fly",1);
	set("objects", ([
		__DIR__"npc/xin2" : 1,
	]));   
	setup();
}

void pushout(object me)
{
	call_out("do_greeting",5,me,this_object());
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

