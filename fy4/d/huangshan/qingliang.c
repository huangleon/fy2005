#include <ansi.h>
#define FATEMARK "����B/��ɽ_�ճ�"

inherit ROOM;
void create()
{
        set("short", "����̨");
        set("long", @LONG
ɽ·���ۣ�һ·���ɡ���ʯ���������������ֻ��һ��ƽ̹�ľ�ʯ��ǰͻ
�����γ�һ��������յ�Σ�ң��Ա�ɢ�����һЩʯ�飬���˶�������ۿ��ճ���
�����⿴�����ƺ�������Ľ������ʣ�¶���ƺ�ɽͷǡ�������ɵ�����Լ�ɼ�һ��
����¥���ɽ�����ɹְأ��е�����ӥ�����չ�ᣬ�е�����Ů��ͤͤ��������
��ʤ�ա�
LONG
        );
    	set("exits", ([
		"southwest" : __DIR__"diezhang",
  		"northwest" : __DIR__"feilong",
  		"east" : __DIR__"shizi",
	]));
	set("item_desc",([
		"rock":	"һ��ƽ̹�ľ�ʯ������������ЪϢһ��sitdown����\n",
		"��ʯ":	"һ��ƽ̹�ľ�ʯ������������ЪϢһ��sitdown����\n",
	]));
		
	
    	set("outdoors", "huangshan");
      	set("coor/x",-120);
      	set("coor/y",0);
	set("coor/z",30);
	setup();
}

void init() {
    	add_action("do_sitdown", "sitdown");
    	add_action("do_standup", "standup");
}

void init_scenery()
{
        remove_call_out("sun_rise");
        call_out("sun_rise", 1, random(2), 0);
}

int do_standup()
{
	object me;
    	me = this_player();
    	if(me->is_busy())
	    	return notify_fail("������æ��\n");
	if(me->is_fight())
    		return 0;
	if(!me->query_temp("watch_sunrise"))
	     	return 0;
	me->set_temp("watch_sunrise", 0);
    	message_vision("$Nվ��������\n", me);
    	return 1;
}

int do_sitdown(string arg)
{
	object me, who;
	mixed *local;
	int dayTime, j;

	me = this_player();
	if(me->is_busy() || me->is_fight())
		return notify_fail("������æ!\n");
	
	if(me->query_temp("watch_sunrise"))
        	return notify_fail("���Ѿ�������ѽ��\n");

    	message_vision("$N���˿�ʯͷ����������������\n", me);
    	me->set_temp("watch_sunrise", 1);
    	
    	if(NATURE_D->is_day_time()) {
  	    return notify_fail("ɽ�����µĿ������㾫��һ��\n");
	} else {
		local = NATURE_D->get_current_time();
		dayTime = local[5];
		if(dayTime < 240) {
	    		return notify_fail("����һƬ��ڣ�������ž���ҹ�ж������š�\n");
		} else if (dayTime > 1080) {
	    		return notify_fail("��ʱ�����ĳ�������ڼž���ҹ�д�����Զ��\n");
		} else if (dayTime > 290 && dayTime < 360) {
		    	return notify_fail("��ɫ��΢�������紵������ȫ����\n");
		} else {
	   	    	tell_object(me, "ɽ�У��ž���ҹ������һ����ζ����ͷ��\n");          	
	    	}
	}
	return 1;
}

void add_fate_mark(object ob)
{
	int num = 1 + random(10);
	if(!random(2) && !ob->query(FATEMARK)) {
		ob->set(FATEMARK, num);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) �õ�"+FATEMARK+" "+num+"�� %s \n",
				ob->name(1), geteuid(ob), ctime(time()) ));
	}
}

void sun_rise(int sunrise, int sunrise_stage)
{
    	object ob,*ppls;
    	int i, j;
        function f=(:add_fate_mark:);
    	remove_call_out("sun_rise");
    	ob=this_object();
	ppls=filter_array(all_inventory(ob),(:userp($1) && interactive($1) && $1->query_temp("watch_sunrise"):));

	if(sunrise_stage == 0 && random(10) > 2)
	{
        	message("vision", HIW"����һƬ����ãã����ʲôҲ���������\n"NOR, ob);
	} else
	if(sunrise == 0)
	{
        	switch(sunrise_stage)
        	{
            		case 0:
                		message("vision", RED"\nһ���ɫ�Ĺ�â������ɽ������������ʱ����ҫ�ۣ����к�ǿ����Ⱦ����ɽ��\n�Ķ�������Ⱦ�ɺ�ɫ�� \n\n"NOR, ob);
         			call_out("sun_rise", 5, 0, 1);
            		    	break;
            		case 1:
                		message("vision", HIR"\n�ۺ�ɫ��̫�������Ĵ�ɽ�ͺ�����ɽ�Ⱥ�Ȼ�������������������ֵ�ɽ��ֹ\n�˽�����һȺȺ����Զ�������ڳ��������һ����鶯��ԶӰ��\n"NOR, ob);
                		call_out("sun_rise", 5, 0, 2);
                		break;
            		case 2:
                		message("vision", HIR"\nһ�ֺ���ӳ����ߵĲ�ϼ�����شӶ�������\n"NOR, this_object(), ob);
                		message("vision", HIY"\n̫������Ծ���ڷ���֮�ϣ����ﶼ��������һ�㵭���Ľ�ɫ�� \n"NOR, ob);
                		j = NATURE_D->get_season();
                		if (j == 1)
                		{
                    			message("vision", HIR"\n��ɽ���Ķž黨Ҳ�����˵����Ľ�ɫ������ϼ���������������ʵ���ɫ��\n"NOR, ob);
                    			message("vision", HIR"����ʧ������ʵ������\n"NOR, ob);
                    			if(sizeof(ppls))
						map_array(ppls,f);
				}
				for(i=0;i<sizeof(ppls);i++)
				{
                		       	message_vision("$N����վ��������\n", ppls[i]);
        	                	ppls[i]->set_temp("watch_sunrise", 0);
        	                }
        	        break;
        	default:
        		return notify_fail("something wrong\n");
	        }
    } else {
 	       switch(sunrise_stage)
 	       {
            		case 0:
                		message("vision", RED"\nãã�������õĴ󺣰��̿�������Զ�����������ĵط���ǳǳ��͸��õ����ɫ��\n"NOR, ob);
                		message("vision", RED"��ɫ�������죬���ܽ����ɢ������ \n"NOR, ob);
                		call_out("sun_rise", 5, 1, 1);
                		break;
            		case 1:
                		message("vision", HIR"\n���õĺ�ϼ�ϣ�����������һ�ߺ�����Բ����ɲʱ���ƺ���Ⱦ�����һƬ�貵�\n"NOR, ob);
                		message("vision", HIR"��졣�Ƴ��������������ɴ�������\n"NOR, ob);
               			call_out("sun_rise", 5, 1, 2);
                		break;
		        case 2:
                		message("vision", HIR"\nһ�ֺ���ӳ����ߵĲ�ϼ�����شӶ�������\n"NOR, this_object(), ob);
                		message("vision", HIR"\nһ�ֺ��ո�����������õ��ƺ��ϣ����ν���ƽϢ������ʱ�任����죬ǳ�죬\n�ۺ��ɫ�ʡ�\n"NOR, ob);
                		message("vision", HIR"\n������ɢȥ��������ϼ��׺����ʡ�\n"NOR, ob);
                		j = NATURE_D->get_season();
                		if (j == 4)
                		{
                    			message("vision", HIW"\n�����ɫ��ӳ��ɽ�ϰ�ɫ�Ļ�ѩ����һ��˵�����Ĵ������������\n"NOR, ob);
                    			if(sizeof(ppls))
						map_array(ppls,f);
				}
				for(i=0;i<sizeof(ppls);i++)
				{
                		       	message_vision("$N����վ��������\n", ppls[i]);
        	                	ppls[i]->set_temp("watch_sunrise", 0);
        	                }

                		break;
        		default:
        			return notify_fail("something wrong.\n");
        	}
    	}
}

int valid_leave(object who,string dir) {
	if(who->query_temp("watch_sunrise")) {
		return notify_fail("���������أ�Ҫվ������standup�������뿪��\n");
	}
	return 1;
}
