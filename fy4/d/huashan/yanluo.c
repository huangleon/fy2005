
inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
��Ϊ��ɽ��߷壬վ�ڷ嶥�Ĵ�������ֻ��ɽ��������Բ�ãã����˵������
��ɽ̫�ߣ����㵽����Ҳ�ɲ���ȥ������������ЪϢ����ȡ������塣�嶥���н�
�칬�����ȫΪ��Ƭ���ߣ�����������Ժǰ���ű߻������ӹ�¥��
LONG
        );
    set("exits", ([ 
  		"eastdown" : __DIR__"shanlu",
	    "north" : __DIR__"yangtian",
	    "westdown" : __DIR__"shanlu1",
	]));

   	set("fall_down", 0);
    set("outdoors", "huashan");

	set("coor/x",-45);
	set("coor/y",-60);
	set("coor/z",40);
	setup();
}


int girl(object me){
	object yu, fang;
	
/*	if(me->query("marks/��������")){
		return 0;
	}*/
	if(!interactive(me) || environment(me) != this_object()) {
		if(yu = present("yu yifei", this_object())) {
			message_vision("$N�����������Ҳ�����ˡ���\n", yu, me);
			message_vision("$Nת��첽��ȥ��\n", yu);
			destruct(yu);
		}
		return 0;
	}
	if(!present("yu yifei", this_object()) || present("fang girl", this_object())) {
		return 0;
	}
	fang = new(__DIR__"npc/fang");
	if(objectp(fang)){
		fang->move(this_object());
		fang->set("target", me);
	}
	fang->fall(me);
}

