// �ص�
inherit ROOM;
void create()
{
        set("short", "�ص�");
        set("long", @LONG
������ĵص����㲻֪��Ҫ����ò��ܳ�ȥ��
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"maoroom1",
  "westdown" : __DIR__"didao1",
]));
	set("coor/x",90);
	set("coor/y",-100);
	set("coor/z",-35);
	setup();
	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        if( userp(me) && dir == "westdown")
                    message_vision("$N�ֽŲ��ã���ص����ȥ\n",me);

        return 1;
}

