// Room: zhangstall.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "���ż���̯");

	set("long", @LONG
����ͷ����̯����ʯ��·�սǴ�����С�����ܸɾ�������������в�Ӭ������
�������Ǵ��Ը����շ����������ͷ������Ҳ����ܺã�ÿ���״򲻶����Ͽ���
�͵��������س������ಶ����ϴ��������һ���ֵ��ǡ�
LONG);

	set("type","street");
	set("exits",([
    "northwest":__DIR__"stoneroad3",
	]) );

        set("objects", ([
                __DIR__"npc/oldzhang": 1,
        ]) );
        set("indoors", "libie");
	set("coor/x",5);
	set("coor/y",-10);
	set("coor/z",0);

	setup();
	replace_program(ROOM);
}
