//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
void create()
{
    set("short", "���ĸ�ֺ�");
    set("long", @LONG
�����Ƿ��Ƴ����ĸ�ķֺţ�һ��С�ɾ��µĵ��̣�������д�š����ĸ���
�֣�û��ʲô�����챦��ֻ���������ĺ�ľ��������Ż�ͭ����������������һ
Щϡ��ŹֵĶ�������˵�������˵��������ķ����ٵá����ĸ���ϰ����ƺ�����
�������ϣ��������������������ؿ��顣
LONG
    );
    set("exits",
      ([
		"north": __DIR__"skystreet4",
      ]));
    set("objects",
      ([
			__DIR__"npc/shaman" : 1,
      ]));
    set("coor/x",20);
    set("coor/y",-170);
    set("coor/z",30);
    setup();
    replace_program(ROOM);
}
