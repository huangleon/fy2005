inherit ROOM;

void create()
{
	set("short", "ɽ��С·");

	set("long", @LONG
��������֪ͨ���δ���ɽ��С·��·�Ե�׺��Щ��ƣ���ף���죬���ϵ�
С����ɷ������ϲ������Զ����[37mɽ��[32m���������ţ�ϯϯ���������Զ��С����
�˼Ҵ�����������㲻����Щ�����ꤣ���֪���δ����ٵ�Щ�óԵķ��ˡ�
LONG);
	set("outdoors", "fugui");
	set("type","road");
	set("exits",([
		"southeast":__DIR__"shanlu1",
		"northwest":__DIR__"shanlu3",
	]) );
	        set("objects", ([
                __DIR__"obj/flower1" : 1,
                __DIR__"obj/brook" : 1,
        ]) );
        set("resource/water",1);
		set("liquid/name","ɽ��ˮ");
		set("liquid/type", "water");
		
	set("coor/x",0);
	set("coor/y",130);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
