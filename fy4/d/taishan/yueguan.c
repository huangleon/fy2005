#include <ansi.h>
#define FATEMARK "����A/̩ɽ_����"

inherit ROOM;

void create()
{
  set("short","�¹۷�");
  set("long",@LONG
���ƴ�ķ嶥�Ͻ���һ��Сͤ�ӣ�ͤ����С�����������ɽ֮�ϣ�Ҳ�ǲ��ף�
�չ۷�ĺ��գ��¹۷�Ľ��¶��Ǽ��ÿ��ľ��£�ÿ�����֮ҹ���¸������ϣ���
��ʤ�գ���ǡ�������ˬ֮ʱ���������£��˷���裬��֮���£�ʵ���޿ɱ��⡣
�¹۷�����ǰ�У�������������Ӣ������֮�ء������޹�ɽׯ����
LONG
  );
    set("exits",([
	    	"down" : __DIR__"shanfeng",
        	"northup" : __DIR__"yushijie3",
    ]));
    
        set("objects", ([
                __DIR__"npc/mantrainer" : 1,
        ]) );
    	set("outdoors", "taishan");
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",125);
	setup();
}


void add_fate_mark(object ob)
{
	int num = 1 + random(10);
	if(!random(3) && !ob->query(FATEMARK)) {
		ob->set(FATEMARK, num);
		tell_object(ob,HIG"\n������û�����ɽ��ǰ����ĬĬ�����������˸�Ը��\n"NOR);
		log_file("riddle/FATE_LOG",
			sprintf("%s(%s) �õ�"+FATEMARK+" "+num+"�� %s \n",
				ob->name(1), geteuid(ob), ctime(time()) ));
	}
}

void init_scenery()
{
        remove_call_out("falling_star");
        call_out("falling_star",1);
}

void falling_star() {
    	object *ppls, room = this_object();
    	function f=(:add_fate_mark:);
    	message("vision", HIW"\n    һ����ɫ�ǹ⻮������ɫ��ҹ�գ�û�����ɽ�͵ĺ��档 \n"NOR, room);
    	message("vision", HIC"ֻ������������һƬ��\n"NOR, room);
    	ppls=filter_array(all_inventory(room),(:userp($1) && interactive($1) :));
    	if(sizeof(ppls))
		map_array(ppls,f);
}
