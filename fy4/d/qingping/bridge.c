//XXDER
inherit ROOM;
void create()
{
    set("short", "����");
    set("long", @LONG
һ��С�ɾ��ƵĹ��ź���ڳ����ϣ�������������һ��Ϊ�����������ˮ����
�峺�����渡��Щʢ����˯����͸��˯���ķ�϶��Լ�ɼ���β��ɫ������ˮ������
�ػ����ζ���Զ����ǽ���µ�һ�԰Ž������Ļ��俪�������֣����������ĳ���
��������������
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"eastdown" : __DIR__"backdoor",
	"westdown" : __DIR__"pond",
      ]));

    set("objects", ([
	__DIR__"npc/qin": 1,
      ]) );
    set("coor/x",10);
    set("coor/y",0);
    set("coor/z",10);
    setup();

    set("outdoors", "qingping");
}

void init()
{
    add_action("do_search", "search");
}

int do_search (string arg)
{
    object me, obj;
    int clvl;

    me = this_player();
    
    if(!arg || arg != "bridge" && arg != "��") {
    	tell_object(me,"�������Ķ�������\n"); 
		return 1;
	} 
	
	clvl = (int)me->query("kar");
    if(me->query_temp("marks/bridge")) {
		message_vision("$N̽ͷ���˿��űߵ�ʯͷ��\n", me);		
		tell_object(me, "��ƾ�ŶԺڰߵص��ӡ������ϸϸ�ز鿴��һ���űߵ�ʯͷ��\n");
		if(clvl > 19) {
		    if(random(100) < clvl) {
			tell_object(me, "�㷢����ͷ��һ��ʯͷ�ϰ���ȥ��һ�飬�ڰ���ȥ�ĵط���һ��С�ס�\n"); 
			me->set_temp("marks/key",1);
			return 1;
		    }
		}
		else {
		    if(random(300) < clvl) {
				tell_object(me, "�㷢����ͷ��һ��ʯͷ�ϰ���ȥ��һ�飬�ڰ���ȥ�ĵط���һ��С�ס�\n"); 
				me->set_temp("marks/key",1);
				return 1;
		    }
		    else 
				tell_object(me, "��ʲôҲû���֡�\n");       
		    return 1;
		}
    }
    message("vision", me->name()+"�ƺ�����Ѱʲô��\n", environment(me), me);
    tell_object(me, "��ʲôҲû���֡�\n");       
    return 1;
}


void key_notify(object obj, int i)
{
    object me;
    me = this_player();
    if(me->query_temp("marks/key")) { 
		tell_object(me, "���Կ�ײ���ʯ�ף�����ת�˼��¡�\n");
		me->start_busy(2);
		call_out("open_door", 5, me);
		return;
    }
    return;
}

void open_door(object me)
{
    int llvl;

    llvl = (int)me->query("kar");

    if(me && environment(me) == this_object()) {
	if(random(100) < llvl)  {
	    me->set_temp("marks/opened",1);
	    tell_object(me, "ƽ���ĳ���ˮ�����ƺ�����һ��СС�����У�����ϸ�ǿ��������ġ�\n");
	}
	else 
	    tell_object(me, "��û�ио����κα仯��\n");
    }
    return;
}
