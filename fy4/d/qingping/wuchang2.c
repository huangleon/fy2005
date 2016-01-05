inherit ROOM;
void create()
{
        set("short", "�䳡");
        set("long", @LONG
�����䳡���ˣ���Ȼ���󣬿��Ǹ����������ʩһӦ��ȫ���������ĳ߸ߵ�
÷��׮�����Ŷ�ǽһ���ſ�������שʯ��ɳ��������Ӳ�������Ͻ������ݣ��ɼ���
����ƽʱ���Ǽ�Ϊ�̿࣬�������Ṧ����Ӳ������ͬѰ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"wuchang1",
	]));

   	set("item_desc", ([
      		"÷��׮": "
÷��׮���������ĳߵ�ľ׮��ɣ���÷��״�ֲ�����������ϰ�Ṧ�ģ�lian����
������Ҫ���������棬Ҫ�е��Ṧ�Ļ�����60��������Ҳ����̫����12����\n",
		"שʯ"	: "������ʯ��ש����Լ���죬��������ϰӲ���ģ�lian����
��������֪������û��������͡�������\n",			
   	]));
   	set("outdoors","qingping");
	set("coor/x",-60);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	
}

void init()
{
   	add_action("do_lian", "lian"); 	
}


int do_lian(string arg)
{
   	object me;
   	int	s, amount, da;
  
   	me = this_player();
   	
   	if(!arg) 
   		return notify_fail("������ʲô��\n");
   	
   	if (arg == "שʯ") {
	   	if( me->is_fighting() )
	      		return notify_fail("��ս������ϰ����������\n");
	   	if( me->is_busy() )
	      		return notify_fail("����һ��������û����ɣ�������ϰ��\n");

   		message_vision("$N������ש�����һ�������Լ�������������ȥ��\n",me);
   		message_vision("ֻ�����һ��������������\n",me);
   		me->unconcious();	
 		return 1;   		
   	}
   	
   	if (arg == "÷��׮" || arg == "zhuang") {  		 	
	   	
	   	if( me->is_fighting() )
	      		return notify_fail("��ս������ϰ����������\n");
	   	if( me->is_busy() )
	      		return notify_fail("����һ��������û����ɣ�������ϰ��\n");
	   	me->start_busy(2);
	   	s = (int)me->query_skill("move", 1);
	   	if(random(30) && me->query("kar")>11) {
		      	if(s >= 75) {
		        	message_vision("\n$N������𣬷ɿ����÷��׮������һȦ��������������������\n", me);
		         	tell_object(me, "����Ṧ����û��ʲô������\n");
		        
			        if (QUESTS_D->verify_quest(me,"��ƽ÷��׮")) {
			      		if (!me->query_temp("marks/qp_lian_start")) {
			      			me->set_temp("marks/qp_lian_start",1);
			      			me->delete_temp("marks/qp_lian");
			      		}
			      		me->add_temp("marks/qp_lian",1);
			      		if (me->query_temp("marks/qp_lian")>=10) {
			      			QUESTS_D->special_reward(me,"��ƽ÷��׮");
			      			me->delete_temp("marks/qp_lian");
			      			me->delete_temp("marks/qp_lian_start");
			      		}
			      	}
		         	return 1;
		      	} 
		      	if(s >= 60) 
		               	message_vision("\n$N������𣬷ɿ����÷��׮������һȦ��������������������\n", me);
		        	
		      	else 
		         	message_vision("\n$NС�ĵ�������÷��׮����ս�ľ�������һȦ���Ͽ�������������\n", me);
		      
		      	da = 20;
		      	me->set_temp("last_damage_from","����÷��׮����С�ĵ�����ˤ���ˡ�");
		      	me->receive_damage("kee", da);
		      	
		      	if (s>=60)
		      	{
		      		tell_object(me, "����Ṧ���󳤽���һЩ��\n");
		      		amount = me->query("agi") + me->query("int") + me->query_skill("move",1)*25;
		      		if(amount < 1) amount = 1;
		      		me->improve_skill("move", amount);
			}
		      	if (QUESTS_D->verify_quest(me,"��ƽ÷��׮")) {
		      		if (!me->query_temp("marks/qp_lian_start")) {
		      			me->set_temp("marks/qp_lian_start",1);
		      			me->delete_temp("marks/qp_lian");
		      		}
		      		me->add_temp("marks/qp_lian",1);
		      		if (me->query_temp("marks/qp_lian")>=10) {
		      			QUESTS_D->special_reward(me,"��ƽ÷��׮");
		      			me->delete_temp("marks/qp_lian");
		      			me->delete_temp("marks/qp_lian_start");
		      		}
			}
		      	
		      	
	   	} else {
	      		message_vision("\n$N���������������÷��׮������һȦ��\n", me);
	      		message_vision("\n$N��ѽһ����÷��׮�ϵ���������\n", me);
	      		da = 100;
	      		me->set_temp("last_damage_from","����÷��׮����С�ĵ�����ˤ���ˡ�");
	      		me->receive_damage("kee", da);

						        
			        if (QUESTS_D->verify_quest(me,"��ƽ÷��׮")) {
			      		if (!me->query_temp("marks/qp_lian_start")) {
			      			me->set_temp("marks/qp_lian_start",1);
			      			me->delete_temp("marks/qp_lian");
			      		}
			      		me->add_temp("marks/qp_lian",1);
			      		if (me->query_temp("marks/qp_lian")>=10) {
			      			QUESTS_D->special_reward(me,"��ƽ÷��׮");
			      			me->delete_temp("marks/qp_lian");
			      			me->delete_temp("marks/qp_lian_start");
			      		}
			      	}

	        }
	   	return 1;
	}
	return notify_fail("��û���������\n");
}