inherit ROOM;
int check_container(object ob);
void create()
{
        set("short", "ǧ��¥");
        set("long", @LONG
������ǵ���켫һʱ�ķ��³�����ǧ��¥�����յ����ɫ�Ĵ����ƺ�����û�䣬����
��ЩƯ���Ĺ��������Ѿ���֪���٣�ֻʣ���ſ���ֻʯʨ����Ȼ��������������
��һЩ��
long
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : "/d/fy/swind4",
]));


	set("outdoors","fengyun");
        set("objects", ([
        __DIR__"npc/" : 2,
                        ]) );
	set("coor/x",-10);
	set("coor/y",-40);
	set("coor/z",-300);
	setup();
}




