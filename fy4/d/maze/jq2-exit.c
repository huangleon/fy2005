// Sinny-silencer@fy4 workgroup 

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�޼������");
	set("long", @LONG
Ҳ��֪���˶�ã���Ѫ�����ڵ��˾�ͷ��ǰ����һ��ʮ�ֿ����Ĵ��ã��Ľ�
��ȼ��ţ��ȴ��һ����ɫ�Ļ��棬���Ŵ󿪣������������ƣ����ɿ����е���
���˵����ˣ��������ڹ���Щ�����ģ�������Ƭ�̱���ε���
LONG
	);
	set("no_clean_up", 0);
	set("no_fly",1);
	set("exits",([
		"west" : __DIR__"jq2-maze/exit",
		"east" : __DIR__"jq2-end",

	]));
        set("objects", ([
                
        ]) );
        set("item_desc", ([
		"east": "�������������ԶԶ��ȥʲôҲ��������ֻ�е������˵����ˡ�\n",
	]) );
	setup();
	
}

int	valid_leave(object who , string dir) {
	object room, guo;
	
	if (dir == "east") 
	{
		room = find_object(__DIR__"jq2-end");
                if (room && room->usr_in())
			return notify_fail("���������������Լ����Ӱ�ζ���\n");
		if (REWARD_D->riddle_check(who,"�ٴ���Ǯ")<2) 
			return notify_fail("�������������û�¶����Ǳ��ȥ�˰ɡ�\n");
		if (room) {
			if (guo = present("guo songyang",room))
				destruct(guo);
			room->reset();
		}
	}
	return ::valid_leave(who,dir);
}