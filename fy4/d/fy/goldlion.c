inherit ROOM;

void create()
{
    set("short", "��ʨ�ھִ�Ժ");
    set("long", @LONG
���Ｘʮ��������û��ʲô�仯��[33m��ʯ[32m�̵أ���Ժ�ұ����ҵķ���һЩ��С��
һ��[37mʯ��[32m��������ھ��е������������������ġ����������ڴ�ϸһ�˶�ߵ�[37m÷
��׮[32m������ͷ�����������׼ҵ��ӳ�����Ȼ�̳���ͽ�ܲ���ô�������������Ṧ
���Ʒ����Ѿ�¯�����ˡ�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"ecloud3",
	"east"  : __DIR__"ghall", 
	"northwest" : __DIR__"gcang",
	"southwest" : __DIR__"gkitchen",
      ]));
    set("objects", ([
	__DIR__"npc/biaoshi" : 1,
	__DIR__"npc/biaoshi1": 1,
      ]) );
    set("outdoors", "fengyun");

    set("coor/x",160);
    set("coor/y",-60);
    set("coor/z",0);
    set("map","fyeast");
    setup();
}

void init(){
    add_action("do_look","look");
    add_action("do_lift","lift");
    add_action("do_lian","lian");
}


int do_lift(string arg)
{
    object me;
    int	s, amount, da;

    if(!arg) 
	return notify_fail("�����ʲô��\n");

    if (arg != "ʯ��" && arg != "stonehammer") 
	return notify_fail("��û���������\n");

    me = this_player();
    if( me->is_fighting() )
		return notify_fail("��ս������ϰ����������\n");
    if( me->is_busy() )
		return notify_fail("����һ��������û����ɣ�������ϰ��\n");
    
    me->start_busy(2);
    s = (int)me->query_skill("unarmed", 1);
    
    if(random(30) && me->query("kar")>10 && s>= 10) {
		if(s >= 40) {
		    message_vision("\n$N����һ��������ص�ʯ����Ҳ��������ʲô���Ͱ����ӵ��˼��߸ߡ�\n", me);
		    tell_object(me, "��Щʯ��������˵�Ѿ�̫���ˡ�\n");
	
		    if (QUESTS_D->verify_quest(me,"��ʨʯ��")) {
				if (!me->query_temp("marks/js_lift_start")) {
				    me->set_temp("marks/js_lift_start",1);
				    me->delete_temp("marks/js_lift");
				}
				me->add_temp("marks/js_lift",1);
				if (me->query_temp("marks/js_lift")>=10) {
				    QUESTS_D->special_reward(me,"��ʨʯ��");
				    me->delete_temp("marks/js_lift");
				    me->set_temp("marks/js_lift_start",1);
				}
		    }
	
		    return 1;
		} 
		if(s >= 20) 
		    message_vision("\n$N�ٵ�һ����վ����׮���Ѹ���ʮ���ʯ���������������Ƶġ�\n", me);
		else 
		    message_vision("\n$Nҧ�����أ�С���ǵ�ͨ�죬����ΡΡ�ذѸ���ʮ���ʯ���ٹ�ͷ����\n", me);
	
		tell_object(me, "��Ĳ���֮�����󳤽���һЩ��\n");
		amount =  me->query("int") + me->query("str") + me->query_skill("unarmed",1)*25;;
		
		if(amount < 1) amount = 1;
		me->improve_skill("unarmed", amount);
		
		da = 20;
		me->set_temp("last_damage_from","�����ز�С�ı�ʯ�������������ˡ�");
		me->receive_damage("kee", da);
	
		if (QUESTS_D->verify_quest(me,"��ʨʯ��")) {
		    if (!me->query_temp("marks/js_lift_start")) {
			me->set_temp("marks/js_lift_start",1);
			me->delete_temp("marks/js_lift");
		    }
		    me->add_temp("marks/js_lift",1);
		    if (me->query_temp("marks/js_lift")>=10) {
			QUESTS_D->special_reward(me,"��ʨʯ��");
			me->delete_temp("marks/js_lift");
			me->delete_temp("marks/js_lift_start");
		    }
		}

    } else {
		message_vision("\n$N�ٵ�һ����һҧ������ʯ����\n", me);
		message_vision("\n��û�������ߣ�$N��һ��ʯ���������������Լ��ű��ϣ���ʹ��\n", me);
		da = 100;
		me->set_temp("last_damage_from","�����ز�С�ı�ʯ�������������ˡ�");
		me->receive_damage("kee", da);


		if (QUESTS_D->verify_quest(me,"��ʨʯ��")) {
			if (!me->query_temp("marks/js_lift_start")) {
			    me->set_temp("marks/js_lift_start",1);
			    me->delete_temp("marks/js_lift");
			}
			me->add_temp("marks/js_lift",1);
			if (me->query_temp("marks/js_lift")>=10) {
			    QUESTS_D->special_reward(me,"��ʨʯ��");
			    me->delete_temp("marks/js_lift");
			    me->set_temp("marks/js_lift_start",1);
			}
	    }

    }
    return 1;
}

int do_lian(string arg)
{
    object me;
    int	s, amount, da;

    if(!arg) 
	return notify_fail("������ʲô��\n");

    if (arg != "÷��׮" && arg!= "zhuang") 
	return notify_fail("��û���������\n");


    me = this_player();
    if( me->is_fighting() )
	return notify_fail("��ս������ϰ����������\n");
    if( me->is_busy() )
	return notify_fail("����һ��������û����ɣ�������ϰ��\n");
    me->start_busy(2);
    s = (int)me->query_skill("move", 1);
    if(random(30) && me->query("kar")>10 && s>=10) {
	if(s >= 40) {
	    message_vision("\n$N������𣬷ɿ����÷��׮������һȦ��������������������\n", me);
	    tell_object(me, "����Ṧ����û��ʲô������\n");

	    if (QUESTS_D->verify_quest(me,"��ʨ÷��׮")) {
		if (!me->query_temp("marks/js_lian_start")) {
		    me->set_temp("marks/js_lian_start",1);
		    me->delete_temp("marks/js_lian");
		}
		me->add_temp("marks/js_lian",1);
		if (me->query_temp("marks/js_lian")>=10) {
		    QUESTS_D->special_reward(me,"��ʨ÷��׮");
		    me->delete_temp("marks/js_lian");
		    me->delete_temp("marks/js_lian_start");
		}
	    }
	    return 1;
	} 
	if(s >= 20) {
	    message_vision("\n$N������𣬷ɿ����÷��׮������һȦ��������������������\n", me);	
	}
	else 
	    message_vision("\n$NС�ĵ�������÷��׮����ս�ľ�������һȦ���Ͽ�������������\n", me);

	tell_object(me, "����Ṧ���󳤽���һЩ��\n");
	amount = me->query("agi") + me->query("int") + me->query_skill("move",1)*25;
	if(amount < 1) amount = 1;
	me->improve_skill("move", amount);
	me->set_temp("last_damage_from","����÷��׮����С�ĵ�����ˤ���ˡ�");
	da = 20;
	me->receive_damage("kee", da);

	if (QUESTS_D->verify_quest(me,"��ʨ÷��׮")) {
	    if (!me->query_temp("marks/js_lian_start")) {
		me->set_temp("marks/js_lian_start",1);
		me->delete_temp("marks/js_lian");
	    }
	    me->add_temp("marks/js_lian",1);
	    if (me->query_temp("marks/js_lian")>=10) {
		QUESTS_D->special_reward(me,"��ʨ÷��׮");
		me->delete_temp("marks/js_lian");
		me->delete_temp("marks/js_lian_start");
	    }
	}

    } else {
		message_vision("\n$N���������������÷��׮������һȦ��\n", me);
		message_vision("\n$N��ѽһ����÷��׮�ϵ���������\n", me);
		da = 100;
		me->set_temp("last_damage_from","����÷��׮����С�ĵ�����ˤ���ˡ�");
		me->receive_damage("kee", da);

		    if (QUESTS_D->verify_quest(me,"��ʨ÷��׮")) {
		if (!me->query_temp("marks/js_lian_start")) {
		    me->set_temp("marks/js_lian_start",1);
		    me->delete_temp("marks/js_lian");
		}
		me->add_temp("marks/js_lian",1);
		if (me->query_temp("marks/js_lian")>=10) {
		    QUESTS_D->special_reward(me,"��ʨ÷��׮");
		    me->delete_temp("marks/js_lian");
		    me->delete_temp("marks/js_lian_start");
		}
	    }

    }
    return 1;
}


int do_look(string arg){
    object me;

    me = this_player();

    if (arg == "ʯ��") {
	tell_object(me, "���СС��ʯ�����������������ģ���������žپٿ���lift ʯ������
������Ҫ���������棬Ҫ�е㲫���Ļ�����10��������Ҳ����̫����11����\n");
	return 1;
    }

    if (arg == "÷��׮") {
	tell_object(me, "��ڴ�ϸһ�˶�ߵ�÷��׮����������ϰ�Ṧ�ģ�lian ÷��׮����
������Ҫ���������棬Ҫ�е��Ṧ�Ļ�����10��������Ҳ����̫����11����\n");
	return 1;
    }

    if (arg == "��ʯ") {
	if (this_player()->query_temp("marks/js_cook_mice") < 2) {
	    tell_object(this_player(),"Ժ�ӵĵ������ú�ʯ�̳ɵġ�\n");
	    return 1;
	}
	tell_object(this_player(),"Ժ�ӵĵ������ú�ʯ�̳ɵģ����������������Щ������һֱͨ�������\n");
	this_player()->set_temp("marks/js_cook_mice",3);
	return 1;
    }

    return 0;
}
