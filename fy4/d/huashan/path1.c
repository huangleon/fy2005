
inherit ROOM;

void create()
{
        set("short", "��ש��");
        set("long", @LONG
������һ�˶�ߵİײ���ᣣ�����ש�̳ɵ�����ֱ��ͨ��ǰ����������ֲ
��һЩ�滨��ݣ��еĿ������ҷ�������ǰ��΢΢����һ���䣬ʹ�㿴����ǰ��
�ľ��ֻ��ת��֮���������ɸ��Ų�ˮ����
LONG
        );
    set("exits", ([ 
  		"southeast" : __DIR__"yuquan",
		"north" : __DIR__"yupond",
	]));
   
    set("outdoors", "huashan");
	set("coor/x",-10);
	set("coor/y",15);
	set("coor/z",-10);
	set("objects", ([
                __DIR__"npc/jin" : 1,
      ]) );
	setup();
}
void open_path()
{
	if( !query("exits/east") ) 
	{
		set("exits/east", __DIR__"hpath1");
        call_out("close_path", 5);
	}
}
void close_path()
{
	if( !query("exits/east") ) return;
	delete("exits/east");
}
