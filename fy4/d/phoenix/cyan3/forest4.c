// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", YEL"������"NOR);
    set("long", @LONG
������խ��ɽ�죬ӭ�������һƬ���ص����֡���δ�����ĸ��ֲ����ľ
��������ں�����������Ų��þ�Ȼ����ԶԶ��ȥ������ī���ϻ�δ������
ľ�塣��ͷ������������������ľҶ����һƬ�Ա̣���������ǳǳ�Ķ�ƣ�
֦����ƽ�ߣ�����Ϊһ��������ܵ�������
    ��֪���ļ��ڣ�΢�硣
    ��ɫ�Ĺ��ߴ�������ǳǳ��͸��������
LONG
NOR
        );
	set("objects", ([


	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"westup" : "path6",
  		"northup" : "forest5",
  		"southup" : "rock",
  		"eastdown" : "path4",
	]) );
	set("area","cyan3");

	set("coor/x",-40);
	set("coor/y",30);
	set("coor/z",70);
	setup();
}

void trigger(object me)
{
	object ob;
	message_vision(CYN"\n����һƬŨ�ص�Ѫ��ζ���������۾�����ǰ������һ��������ۡ�����ʹ������Ů����\n������һϮ��ȹ��Ȼ���ƶദ�������������Ѫ���Ĵ�Ŀ��\n\n",me);
	message_vision(CYN"�����Ķ����ܲ�һ�����ܵĺ��飬ҧ���������ѹ⣬����ĪҪ��������ǰ"WHT"��¶���"CYN"����\n�ǣ�����֪��������������Ϣ˵���������̹��ᣬһ���ұ�ʹ��ɱ�֡�\n\n",me);
	message_vision(CYN"��Ů��Ϣ���ں�������ס�������ݿ��˼������������ڣ������˾��ţ��ҵ�ȥ�����һ�\n�����㣮��һ����ǧ��С�ġ�\n\n",me);
	message_vision(MAG"���ǣ���������"YEL"\n��ü�Ľ��壬������Ů����ײײ����Ӱ��ʧ�ڻ������������°߰ߵ��Ѫ����\n\n",me);

	tell_object(me,HIY"�������ı��ˣ�\n"NOR);

	me->set("quest/short", WHT"��"CYN+"���ƶ�"+WHT"�μ���Ѫƽ�ܴ��"NOR);
	me->set("quest/location", "���ƶ�");
	me->set("quest/duration",3600);
	me->set("quest/quest_type","special");
	me->set("quest_time",time());

	REWARD_D->riddle_set(me,"���Ļ���",1);


	if (present("feng minxin"))
		destruct(present("feng minxin"));

	return;
}


int	valid_leave(object who, string dir)
{
	object me;
	me = who;

	if (dir != "eastdown" && dir != "southup" )
//		if (REWARD_D->riddle_check(me,"���Ļ���") == 1) 
			return notify_fail("ʱ���ϲ����ˣ��ͱ𵽴��һ��˰ɣ�\n");

	return ::valid_leave(who,dir);
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/


