#ifndef _PID_H
#define _PID_H

#include <cmath>
#include <cfloat>

template <class T>
class PIDController
{
public:
  PIDController(double p, double i, double d, T (*pidSource)(), void (*pidOutput)(T output));
  PIDController(double p, double i, double d, T (*pidSource)(void* fContext), void (*pidOutput)(T output, void* fContext), void* context);
  void tick();
  void setTarget(T t);
  T getTarget();
  T getOutput();
  T getFeedback();
  T getError();
  void setEnabled(bool e);
  bool isEnabled();
  T getProportionalComponent();
  T getIntegralComponent();
  T getDerivativeComponent();
  void setMaxIntegralCumulation(T max);
  T getMaxIntegralCumulation();
  T getIntegralCumulation();

  void setInputBounded(bool bounded);
  bool isInputBounded();
  void setInputBounds(T lower, T upper);
  T getInputLowerBound();
  T getInputUpperBound();
  void setOutputBounded(bool bounded);
  bool isOutputBounded();
  void setOutputBounds(T lower, T upper);
  void setOutputLowerBound(T lower);
  void setOutputUpperBound(T upper);
  T getOutputLowerBound();
  T getOutputUpperBound();
  void setFeedbackWrapped(bool wrap);
  bool isFeedbackWrapped();
  void setFeedbackWrapBounds(T lower, T upper);
  T getFeedbackWrapLowerBound();
  T getFeedbackWrapUpperBound();

  void setPID(double p, double i, double d);
  void setP(double p);
  void setI(double i);
  void setD(double d);
  double getP();
  double getI();
  double getD();
  void setPIDSource(T (*pidSource)(void* context));
  void setPIDOutput(void (*pidOutput)(T output, void* context));
  void setPIDSource(T (*pidSource)());
  void setPIDOutput(void (*pidOutput)(T output));
  void registerTimeFunction(unsigned long (*getSystemTime)());

  void reset();
private:
  void* context;

  double _p;
  double _i;
  double _d;
  T target;
  T output;
  bool enabled;
  T currentFeedback;
  T lastFeedback;
  T error;
  T lastError;
  long currentTime;
  long lastTime;
  T integralCumulation;
  T maxCumulation;
  T cycleDerivative;

  bool inputBounded;
  T inputLowerBound;
  T inputUpperBound;
  bool outputBounded;
  T outputLowerBound;
  T outputUpperBound;
  bool feedbackWrapped;
  T feedbackWrapLowerBound;
  T feedbackWrapUpperBound;

  bool timeFunctionRegistered;
  T (*_pidSource)();
  void (*_pidOutput)(T output);
  T (*_pidSourceContext)(void* context);
  void (*_pidOutputContext)(T output, void* context);
  unsigned long (*_getSystemTime)();
};

#endif //_PID_H
