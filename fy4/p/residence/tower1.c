

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",1);

  set ("short", "�������ײ�");
  set ("long", @LONG

����һ����
�������������ȥ������һ����ʧȥ���ж���
������������ֻ����ʣ�µĻ��ж���
������������������ô��һ����ñȽϿ��֡�

��������������������������1985��5��4�գ�����֮ǰ��

LONG);
        set("exits", ([
"106" : __DIR__"userroom/hzl1396821442",
"105" : __DIR__"userroom/tgl1396820489",
"104" : __DIR__"userroom/ajump1396597107",
"103" : __DIR__"userroom/hjp1396319481",
"102" : __DIR__"userroom/ldb1396243050",
"101" : __DIR__"userroom/mhub1396003783",
  //"down" : __DIR__"tower1",
  "up" : __DIR__"tower2", 
  "west" : __DIR__"enterance",
]));
  	set("coor/x",-10);
	set("coor/y",-40);
	set("coor/z",query("floor")*40);
	setup();
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
