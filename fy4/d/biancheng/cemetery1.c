#include <ansi.h>

inherit __DIR__"cemetery";

string *names=({
	__DIR__"cemetery4",
	__DIR__"cemetery5",
	__DIR__"cemetery2",
	__DIR__"cemetery3",
} );


void create()
{
        set("short", "�س�");
        set("long", @LONG
��ɫ��ɭ����Ҳ���䣬Զ���ߵ�������ص���ĺ��澹��һƬ�ޱ��޼ʵĻķء�
��Ȼ�ǰ��죬�ķؼ���Ȼ��������Ҳ��Ȼ���Թ����ˡ����������������Ե�����
�谵������У�һֻ��Ӱ�����������������������������������м������硣����
Ҳ����ɽ����ˮ����Ұ���ķء�
LONG
        );
        set("outdoors", "biancheng");
        set("coor/x",-70);
	set("coor/y",20);
	set("coor/z",0);
	set("no_lu_letter",1);
	setup();
}

void reset()
{
	int i,j;
	string temp;
	::reset();
	for (i=0;i<=3;i++)
	{
		j=random(4);
		temp=names[j];
		names[j]=names[i];
		names[i]=names[j];
		names[i]=temp;
	}
	set("exits", ([
		"north" : names[0],
		"south" : names[1],
		"east" : names[2],
		"west" : names[3],
	]));
}

/*
int valid_leave(object obj, string dir){
	object another;
	int num;
	
	seteuid(getuid());
	
	if (!present("zombie", this_object()) && random(10)>7) {
		switch (obj->query("quest/quest")) {
			case "�Ͻ�ʬ":	another = new(__DIR__"npc/zombie4");
							break;
			
			case "�߽�ʬ":	another = new(__DIR__"npc/zombie3");
							break;
			
			case "�ݽ�ʬ":	another = new(__DIR__"npc/zombie2");
							break;
			
			case "С��ʬ":	another = new(__DIR__"npc/zombie1");
							break;
		}	
		
		if (!objectp(another)) {
			sscanf(file_name(this_object()),__DIR__"cemetery%d",num);
			switch (num) {
				case 1:
				case 2:
				case 3:
				case 4:	 another = new(__DIR__"npc/zombie1");
						 break;
				case 5:
				case 6:
				case 7:
				case 8:  another = new(__DIR__"npc/zombie2");
						 break;
				case 9:
				case 10:
				case 11:
				case 12: another = new(__DIR__"npc/zombie3");
						 break;
				default: another = new(__DIR__"npc/zombie4");
						 break;
			}
		}		
		another->move(environment(obj));
		message_vision(YEL"�ض�������վ��һ��������������!\n"NOR, obj);	
		return notify_fail(another->name()+"������צ�ص����������ǰ��\n");
	}	
	return 1;
}*/
