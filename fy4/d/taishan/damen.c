// Room: damen.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "�޹�ɽׯ����");

	set("long", @LONG
��������������µ��޹�ɽׯ��.�ԴӶ�����ǰ����Զ����ֿ�ȭ�������޹�
ɽׯ��ֱ�����,ֻҪ���޹�ɽׯ���ӵ�,�����ߵ��δ�,���Ʊر�������������
������Ϊ���������֮��������˥�ܵĽ���,���ֻ�С��޹�ɽׯ��������������
֮������"������˫"��.
LONG);

	//{{ --- by MapMaker
	set("exits",([
	"south":__DIR__"yushijie1",
    "enter":__DIR__"dating",
	]) );
	//}}
        set("outdoors", "taishan");
	set("coor/x",0);
	set("coor/y",60);
	set("coor/z",150);

	setup();
	replace_program(ROOM);
}
