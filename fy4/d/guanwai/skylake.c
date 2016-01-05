inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIB"���"NOR);

	set("long", @LONG
ת��һ��ɽ�֣�Ⱥ�廷��֮�У���Ȼ�ǰ�ãã��һƬ��ˮ��ԭ������������
������ĵ�һ�ߺ��������������ڸ��ﺣ����������ˮ�峺���̲�������������Ƭ
Ƭ����ĸ���������ˮ���죬����ˮ����������������ϡ��ذ���Ϊ����ľ��,
�⼴���������������Ǹ�СС���ٲ���ˮ���ɽ���      
LONG);

	set("type","street");
	set("exits",([
		"southup":__DIR__"shanyao",
	]) );
        set("item_desc", ([
        	"lake": "�����ˮ����ɽ�ϵĺ�ѩ�������亮�Ʊ���\n",
        	"��": 	"�����ˮ����ɽ�ϵĺ�ѩ�������亮�Ʊ���\n",
        	"�ڸ��ﺣ": 	"�����ˮ����ɽ�ϵĺ�ѩ�������亮�Ʊ���\n",
        	"�ٲ�": 		"ˮ���ɽ���������һ��С�ӣ�ͨ��ʥĸ��ɽ�ţ�jump����\n",
        	"waterfall":"ˮ���ɽ���������һ��С�ӣ�ͨ��ʥĸ��ɽ�ţ�jump����\n",
        ]));
        
        set("outdoors", "guanwai");
		set("coor/x",-50);
		set("coor/y",-90);
		set("coor/z",100);
        set("resource/water",1);
     	set("liquid",([
            "name":"��ˮ",
            "container":"�ڸ��ﺣ",
            ]));

	setup();
}

int valid_leave(object me, string dir)
{
	if( userp(me) && dir == "southup" )
	{
        if( me->query("cps")< 20 )
            	return notify_fail("̧ͷԶ����ʥĸѩ��ֱ��������ѩ���죬���ѩ����֪�δ����Ǿ�ͷ��
������һ㤣��ո�����ȥ�ĽŲ��Խ������˻������������裲�����ڶ�����\n");
        else
        {
                 message_vision(HIR "\n\n$N������Ѫ���ڣ�׳�����ң����쳤Хһ��������������֮��������\n\n"NOR,me);
        	 return 1;
        }
	}
	return 1;
}


void	init(){
	add_action("do_dip","dip");
	add_action("do_jump", "jump");
}


int do_dip(string arg){
	
	object weapon, me;
	
	me = this_player();
	
	if (me->is_busy())
		return notify_fail("��������æ��\n");
		
	weapon = me->query_temp("weapon");
	
	if (objectp(weapon))
	{
		tell_object(me, WHT"���"+ weapon->name()+NOR WHT"�����ˮ֮�У�ֻ��һ�ɺ���������������������ס��\n"NOR);
		weapon->set_temp("icy_dipped",1);
	} else
		tell_object(me,WHT"��������Ӱ��ֽ����ˮ֮�У�͸�ĵĺ��Ⱑ��\n"NOR);
	
	me->perform_busy(1);	
	return 1;
}


int do_jump(string arg)
{
        object 	me;
		me = this_player();
		if (me->is_fighting() || me->is_busy())
		{
			write("��������æ��û������ȥ��\n");
			return 1;
		}

		if(!arg) 
		{
			write("��Ҫ�������\n");
			return 1;
		}

		if( arg == "down" || arg == "waterfall" || arg=="�ٲ�")
        {
				message_vision("$N�������˿������������ٲ���Ծȥ��\n",me);
				me->perform_busy(2);
        		call_out("fliping",2,me);
        		return 1;
        }
        else
        {
                write("�㲻������"+arg+"��\n");
                return 1;
        }
}


int fliping(object me)
{
		object room;
		if( !me->is_ghost() && environment(me) == this_object()) 
		{
			room=find_object(__DIR__"shanjiao");
			if (!objectp(room)) room=load_object(__DIR__"shanjiao");
			tell_room(room, me->name() + "ʪ���ܵشӺ�������������\n");
			me->move(room);      		
		}
        return 1;
}
