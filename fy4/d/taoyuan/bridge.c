inherit __DIR__"no_killing_place";
void create()
{
    
	set("short", "С��");
    
	set("long", @LONG
�������ɵ�С��ͨ���ס�ˮ�����Ĵ�������������ˮ�峺���ף�վ����
�����������ؿ�������ʯ�̳ɵĺӴ�����ʱ�ι�������ڶ���ʯ��Ͷ���˵�����
��Ӱ���������಻�ϵ�ɽ�ͻ�����һ����ɫ����أ��������ɽ���������ż�����
�µ�СլԺ�����ܻ��ݷ��衣
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"riverbank",    
		"east" : __DIR__"riverbanke",
	]));
    
	set("no_magic", 1);
	set("outdoors","taoyuan");
	set("coor/x",60);
	set("coor/y",0);
	set("coor/z",0);
    
	setup();
    
	
}
