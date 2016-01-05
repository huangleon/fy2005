#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "����̨");
	set("long", @LONG
����̨���������ϵ�̨ͤ��ֻ���������ϵ�СС��һ�����𣬾�˵����������
ˮ�����������������ӣ����������������������ʵ�����˵��������ġ�������Ҫ
���κ���Ͷ���Ĺ�����������֮�������ᵽ�������������һ�󣬰�ǰ������
���˺������ǣ��������ܹ����ٴ�Ͷ̥���ˡ�
LONG
	);
	set("no_fight", 1);	
	set("exits", ([
        	"northwest"      : __DIR__"pingan",
	]) );
        set("no_meal","���Ȼ���ֿ��е�ʳ����ˮ���˿�ɬ�����࣬�Ͽ����۵����˳�����\n");
	set("objects", ([
	
	]) );

	set("coor/x",40);
	set("coor/y",-80);
	set("coor/z",-190);
	set("no_fight",1);
	setup();
}


int	init(){
	add_action("do_sit","sit");
}



int	do_sit()
{
   	object me;
   	int	s, amount, count;
     	
   	me = this_player();
   	if( me->is_fighting() )
      		return notify_fail("ս��������������������\n");
   	if( me->is_busy() )
      		return notify_fail("����һ��������û����ɡ�\n");
   	me->perform_busy(2);
   	
   	count = me->query("KILLED");
   	s = (int)me->query_skill("perception", 1);
   	if( random(me->query("kar")) > 9) {
	      	if(s >= 50) {
	        	tell_object(me,WHT"�㾲�������£��Ժ��пտյ������������⣬������˵�Ѿ���ȫ�޼ǹҵ��ˡ�\n"NOR);
	         	return 1;
	      	} 
	      	
	      	if (s<= count *10){
	      		tell_object(me,CYN"�㾲�������£��������Ⱳ���߹���·����������������������ȥ���ݣ�\n"NOR);
	        	tell_object(me, "��Ĺ��֮�����󳤽���һЩ��\n");
	      		amount =  me->query("int") + me->query("cps")+s;
	      		if(amount < 1) amount = 1;
	      		me->improve_skill("perception", amount);
	      	} else
	      		tell_object(me,CYN"�㾲�������£��������Ⱳ���߹���·������һЦ��\n"NOR);
   	} else {
      		tell_object(me,CYN"���뾲�������£���ȴ�޷��ͻ��������ÿ���ԩ������\n"NOR);
      		
        }
   	return 1;
}