inherit ROOM;

void create()
{
	set("short", "ӥ�");

	set("long", @LONG
ɽ·������У����������ͱ���Ȯ������ԶԶ��ȥ����������಻�ϡ�ˮ��
���������ֻ��ɽ���һ�������Ƶ��ٲ���к���£�����һ��Ϫ������ʤ��������
���쳣��ˮ��Ю����֦ʯ�飬ת�۱����ò�֪ȥ�����������ɽ����һ����Ȼ��
�ա�ӥ�����ɽ����Զ�����ƺ��м�é������ɽ������
LONG);

	set("type","mountain");
	set("exits",([
		"northdown":__DIR__"wolfslope",
		"southeast":__DIR__"safepub",
	]) );
       set("outdoors", "wolfmount");
        set("item_desc", ([
                "ɽ��": "ɽ��������Ϣ��ˮ���ļ�����ȴʮ���峺��\n",
                "fountain": "ɽ��������Ϣ��ˮ���ļ�����ȴʮ���峺��\n",
        ]) );
    set("resource/water",1);
	set("liquid/name","ӥ�ˮ");
	set("liquid/type", "water");
	set("objects",([
     		__DIR__"npc/tiezhan":1,
    	]) );
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
