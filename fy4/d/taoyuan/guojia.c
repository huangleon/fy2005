inherit __DIR__"no_killing_place";
void create()
{
	set("short", "��լ");
	set("long", @LONG
��ǰ��ũ�ἫΪ�򵥣�����Χ�ɵ�ǽ��Ϊ�����Զ�Ѿ���Щ���䣬é��ձ�ɵ�
�ݶ����ʧ�ޣ�������ſ��Ѳ���ԭɫ�����ߵĶ���Ҳ�Ѳ��ɱ��ϣ���Լ�ɱ��ֻ
���ſ��ϵġ���լ�����֡��ſڵ�����Сʯ�ĵ���������ȱ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
   		"east" : __DIR__"nongjia1",
   		"west" : __DIR__"guojia1",
   	]) );

	set("no_magic", 1);
   	set("outdoors","taoyuan");
	set("coor/x",5);
	set("coor/y",20);
	set("coor/z",0);
	setup();
	replace_program( __DIR__"no_killing_place");
}
																				
																	
