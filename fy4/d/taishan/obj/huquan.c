inherit "/d/fycycle/obj/tutor";

void create()
{
        set_name("ɽ��", ({ "ɽ��","hill", "shanluan" }));  
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("unit", "");
		set("long",
			"ɽ���绢���۰�һ����������צ���������ˣ��鶯���ѣ��ý����ף��ƺ�����
��һ�Ÿ�����书��tigerstrike����\n");
		set("value", 70);
		set("material", "wood");
		set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);
 		set("teaching", "tigerstrike");
 		set("teaching_limit", 200);
 	}
 	
 }
 
 