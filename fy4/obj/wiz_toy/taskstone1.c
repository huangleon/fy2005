//Created by justdoit at Oct 2001 
//All Rights Reserved ^_^
//combat_exp lvl star:200k moon:1.2M sun:2.8M
//skill lvl star:50 moon:100 sun:150

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIY "��Ӱʯ"NOR , ({ "taskstone" }) );
	set_weight(9);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("long", CYN"
�̹ſ�������֮ʼ����س����������ǳ���ת���ϣ�����ʯ��Դ��Զ������׹�����
��һ����ʯ���������¹���������������������Ļ�ɫ��ԣ�������Բ��״����ͼ����
�������֮Ϊ��Ӱʯ����ʯ��һ����ǰ�����˼ӹ�����������书�ĵÿ������ϣ���
������ǰ���������ӵ��ڵ����ڴ�ʯ֮�С��κ���ֻҪ�õ���ʯ��������̥���ǣ���
��������\n"NOR + YEL"
ʯͷ������һ���ΰ�ӡ(moonmark)���պÿ�������һ���˵����ƣ�
�ƺ����ԣУ����\n
"NOR);
		set("value",20000);
		//set("no_get",1);
	}
}

void init()
{
	add_action("pressmark","press");
}

int pressmark(string arg)
{
		object me,room;
		int num, leftover, task_level, task_num;
		me = this_player();

   		if(!arg || arg!="moonmark") return notify_fail("��Ҫ��ѹʲô��");

    	if(arg=="moonmark")  {
		/*if (me->query("rewarded_task")<50) {
			message_vision( HIR "$N���û���������ϣ�������һ�����һ��Ѫ�꣡��\n" NOR, me);
			tell_object(me,"��Ҫ�����������������ʹ�ã�����\n");
			return 1;
		}
		
		if(!wizardp(me)){
			tell_object(me,"��鱦ʯ�������ܹ�ʹ�õģ��������Ӧ�ü�����\n");
			return 1;
		}*/
			
		num = me->query("rewarded_task");
		
		task_level = F_LEVEL->get_level(me->query("combat_exp"));
		task_num = F_LEVEL->level_to_pot(task_level)/10/50;		// 1/10 leveling up reward
    	    	    		
    	if (task_num <= num) {
    		tell_object(me," HEY YOU DONT NEED IT ANYMORE, wait for next level \n");
    		return 1;
    	}
    		
    	//leftover = task_num - num;
leftover = 1;
    	    tell_object(me,HIW"�������һ��TASK����õ�һ�����ۣ�\n���Ǳ�ܵ�������50��\n"NOR);
		   me->add("rewarded_task",leftover);
		   me->add("task_pot",leftover*50);
		   me->add("potential",leftover*50);
		   me->add("TASK", leftover);
		   me->add("score",leftover);
		//   me->add("deposit",5000*leftover);
	   
	   message_vision(HIY "
��Ӱʯ��ʱӨ�����ԣ��ɹ����硣$N����һ�£��������磡����������������һ��ǿ
�Ҹо���������Ӱʯ���˹����㣬����������ױȵľ���������Ҫ�ֽ�$N���Դ�����
��ȥ����ֶ�İ���ľ���׷׳��֣����˷���ü�������У����������ڲ����԰�
��ج�Ρ���Ӱʯ�����Ȳ��Ͼ��������������������£���â��ҫ�������ޱȡ����
���Ļ�����һ̯��ĩ��\n" NOR, me);
		//this_object()->destruct();
destruct(this_object());
room=environment(me);
//message("vision",this_object()->query("name")+"�����Ļ�����һ̯��ĩ��\n",room);
tell_object(me,HIW"�������һ��TASK����õ�һ�����ۣ�\n���Ǳ�ܵ�������50��\n"NOR);
		return 1;
	  }
}	

