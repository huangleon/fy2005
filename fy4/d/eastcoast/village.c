inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
ǰ���Ǹ���壬ʮ�����˼ң��󲿷��ǲ��ݣ���ǰɹ�����������ŷ�ɵ���Ƭ��
�����Ƕ��º�����ȥ�ˣ������Ǵ����ƾɵ�������·��ڴ��˵Ц��ʱ��ʱ̧ͷ��
���������洬����������Ȼ����һƬ��΢΢���Ų��ˡ�������ˮ��ӿ����׵��˻���
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"seaside1",
		"east" : __DIR__"cape",
		"west": __DIR__"village2",
	]));
        set("outdoors", "tieflag");
	set("item_desc", ([
	 ]));
	set("coor/x",1000);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}

