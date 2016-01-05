// TIE@FY3 ALL RIGHTS RESERVED
#include <ansi.h>
#define FATEMARK "����B/��ɽ_���"
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�������ǵڶ��߷壬��Ϊ��γ��ַ�⣬���Ա���Ϊ�������������������ƽ
���������󣬹�����������������������������������ˮ���ӣ�����һɫ�������
��Ե�ɺϣ����������￴���ѵ�һ���ķ�⡣
LONG
        );
	set("exits", ([
  		"south" : __DIR__"feilai",
  		"eastup" : __DIR__"lianhua",
  		"southwest" : __DIR__"paiyun",
  		"north" : __DIR__"sanhua",
	]));

        set("outdoors", "huangshan");
      set("coor/x",-90);
      set("coor/y",-10);
	set("coor/z",30);
	set("objects", ([
//        __DIR__"npc/monkey1" : 1,
                        ]) );


	setup();
}

void init_scenery()
{
/*	object me;
    	int i, dayTime;
    	mixed *local;
	add_action("do_jump", "jump");
    	me = this_player();
    	local = NATURE_D->get_current_time();
    	i = NATURE_D->get_season();
    	dayTime = local[5];
// around 3pm spring or summer afternoon have chance to see foguang
	if ( i != 1 || i != 2)
    		return;
	if(query("start_foguang"))
    		return;
	if (!random(10) && dayTime > 840 && dayTime < 960)
	{
        	set("start_foguang", 1);
        	me->set_temp("foguang", 1);
  */      	remove_call_out("foguang");
        	call_out("foguang", random(6) , 0);
    //	}
}

int valid_leave(object me, string dir)
{
	if ( me->query_temp("foguang"))
	{
    		me->delete_temp("foguang");
//    		delete("start_foguang");
    	}
    	return 1;
}

void foguang(int stage)
{
    	object *ppls, ob;
    	int i;
    	ob=this_object();
    	remove_call_out("foguang");
	ppls=filter_array(all_inventory(ob),(:interactive($1) && userp($1):));
    	if(stage == 0 && random(30) <25)
    	{
        	message("vision", HIW"     һƬ�Ʋʻ����شӷ嶥Ʈ����\n"NOR, this_object());
    	} else
    	{
        	switch(stage)
        	{
        		case 0:
            			message("vision", HIW"\n         �ƻ���Ʈ�˹�����������ɽ��߻����һƬ�ƺ���\n\n"NOR, ob);
            			message("vision", WHT"�ƺ��ޱ��޼ʣ������÷·�һֱ�������쵽���ϡ�����б�գ���紵��������������\n"NOR, ob);
            			message("vision", WHT"����ʵ�ĺ���������࣬ȴҲƽ���˼����Իá�\n"NOR, ob);
				for(i=0;i<sizeof(ppls);i++)
				{
      	    				message_vision("\n$N�������±߿�ȥ��\n",ppls[i]);
      	    				tell_object(ppls[i],"\n�ƺ��任Ī�⣬�㲻�ɵ��뿿����ϸ������\n");
      	    			}
         			call_out("foguang", 5, 1, ob);
            			break;
        		case 1:
	            		message("vision", HIC"\n�ƺ��е���ʲô�������������Ŀ�⣬��Ȼ��һ���˵�Ӱ�ӡ�\n"NOR, ob);
            			message("vision", HIY"ֻ����Ӱ���𽥵�����������������Χ�γ���һ���޴�Ĳ�ɫ�⻷��\n"NOR, ob);
            			call_out("foguang", 5, 2, ob);
            			break;
        		case 2:
            			message("vision", HIM"\n����ϸ��ʱ��ֻ������ʹ⻷�����Ƽʡ��⻷֮�з������Լ�����Ӱ��\n"NOR, ob);
            			message("vision", HIM"Ӱ�����ƣ��ֺ����\n"NOR, ob);
            			message("vision", "\n��ã�����ƺ�����ǰ�ƶ���������\n", ob);
            			//����2����һ��
            			if(sizeof(ppls)<2)
            				break;
            			i=random(sizeof(ppls));
            			message_vision("\n$N�����ã���飬ֱ�����±���ȥ��\n",ppls[i]);
            			//������ѡһλ�����ߣ����ܷ�����ٻ�......
            			ppls[i]->start_busy(4);
            			ppls[i]->set_temp("foguang",1);
            			if (!ppls[i]->query(FATEMARK) )
            				call_out("jump", 3, ppls[i]);
            			else
            			{
            				if (random(10) > 5)
            				{
            					call_out("jump", 3, ppls[i]);
                			} else
                			{
                    				call_out("wake", 3, ppls[i]);
                			}
            			}
            			break;
        		default:
        			return notify_fail("something wrong\n");

        }
    }
}
void wake(object watcher)
{
    	message_vision("\nһ��ɽ�紵����$NٿȻ���ѣ��������²���һ��֮ң��$N����һ���亹��\n", watcher);
	watcher->delete_temp("foguang");
}

int jump(object watcher)
{
	int num = 1 + random(10);
	if( environment(watcher)!=this_object()) return 1;
	if(!watcher->query_temp("foguang")) return 1;//û�����return����
	if (watcher->query("cps") < 10)
	{
    		message("vision", "\n�����ɼ�������������ȥ��\n", watcher);
   		message("vision","\n" + watcher->name() + "��ɫһƬ��ã��������������ȥ��\n",
  				this_object(), watcher);
		watcher->set("����B/��ɽ_���", num);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) �õ�"+FATEMARK+" "+num+"�� %s \n",
				watcher->name(1), geteuid(watcher), ctime(time()) ));
		watcher->start_busy(4);
		if(random(watcher->query("kar"))>10)
	 		call_out("bird", 2, watcher);
	 	else {
	 		watcher->set_temp("last_damage_from","�ڻ�ɽ׹��������\n");
	 		watcher->die();
	 	}	
    	} else {
		message("vision", "\nһ��ɽ�紵��������־��΢���ѣ���������һ����һ��֮ң����Զ������ʹ⻷�ƺ�\n", watcher);
		message("vision", "���������������ߡ������ѡ������������������\n", watcher);
		message("vision", "\nһ��ɽ�紵����" + watcher->name() + "��־�����˹�����\n", this_object(), watcher);
		watcher->set_temp("�������", 1);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) �õ�"+FATEMARK+" "+num+"�� %s \n",
				watcher->name(1), geteuid(watcher), ctime(time()) ));
	}
    	watcher->delete_temp("foguang");
}

int do_jump()
{
	object me;
	me = this_player();
	if(me->query_temp("�������"))
	{
		me->delete_temp("�������");
		message_vision("$N������������ȥ��\n", me);
		me->set("����B/��ɽ_���", 1+random(10));
		me->start_busy(4);
		call_out("bird", 2, me);
		return 1;
	}
	return 0;
}

void bird(object me) {
	object room;
	string target;
	int i;
	string *rooms = ({  AREA_HUANGSHAN"jiyu",
//	                    AREA_XINJIANG"sichou2",
//	                    AREA_QUICKSAND"desert3",
//	                    AREA_QUICKSAND"quicksand4",
	});
	message("vision", "\n������ʹ⻷��������׹ȥ�������Ǻ����ķ�������ǰһƬ������ʲô����������\n", me);
	message("vision", "��������һƬ�հס�\n", me);
	message("vision", "ͻȻ�䣬���ͷ���������ٵ���ë�Ķ������������ż���ϴ���һ���ʹ��\n", me);
	message("vision", "��е���׹�����ƶ���һ�¡�\n\n", me);
	i=sizeof(rooms);
	target = rooms[random(i)];
	room = find_object(target);
	if(!objectp(room))
		room= load_object(target);
	me->move(room);
    	me->unconcious();
	message("vision", "\nһֻ��������ӹ���һ�źں����Ķ����ӿ������¡�\n", environment(me),me);
}
